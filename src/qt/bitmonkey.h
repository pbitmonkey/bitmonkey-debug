// Copyright (c) 2011-2016 The bitmonkey Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITMONKEY_QT_BITMONKEY_H
#define BITMONKEY_QT_BITMONKEY_H

#if defined(HAVE_CONFIG_H)
#include <config/bitmonkey-config.h>
#endif

#include <QApplication>
#include <memory>
#include <vector>

class bitmonkeyGUI;
class ClientModel;
class NetworkStyle;
class OptionsModel;
class PaymentServer;
class PlatformStyle;
class WalletController;
class WalletModel;

namespace interfaces {
class Handler;
class Node;
} // namespace interfaces

/** Class encapsulating bitmonkey Core startup and shutdown.
 * Allows running startup and shutdown in a different thread from the UI thread.
 */
class bitmonkeyCore: public QObject
{
    Q_OBJECT
public:
    explicit bitmonkeyCore(interfaces::Node& node);

public Q_SLOTS:
    void initialize();
    void shutdown();

Q_SIGNALS:
    void initializeResult(bool success);
    void shutdownResult();
    void runawayException(const QString &message);

private:
    /// Pass fatal exception message to UI thread
    void handleRunawayException(const std::exception *e);

    interfaces::Node& m_node;
};

/** Main bitmonkey application object */
class bitmonkeyApplication: public QApplication
{
    Q_OBJECT
public:
    explicit bitmonkeyApplication(interfaces::Node& node, int &argc, char **argv);
    ~bitmonkeyApplication();

#ifdef ENABLE_WALLET
    /// Create payment server
    void createPaymentServer();
#endif
    /// parameter interaction/setup based on rules
    void parameterSetup();
    /// Create options model
    void createOptionsModel(bool resetSettings);
    /// Create main window
    void createWindow(const NetworkStyle *networkStyle);
    /// Create splash screen
    void createSplashScreen(const NetworkStyle *networkStyle);
    /// Basic initialization, before starting initialization/shutdown thread. Return true on success.
    bool baseInitialize();

    /// Request core initialization
    void requestInitialize();
    /// Request core shutdown
    void requestShutdown();

    /// Get process return value
    int getReturnValue() const { return returnValue; }

    /// Get window identifier of QMainWindow (bitmonkeyGUI)
    WId getMainWinId() const;

    /// Setup platform style
    void setupPlatformStyle();

public Q_SLOTS:
    void initializeResult(bool success);
    void shutdownResult();
    /// Handle runaway exceptions. Shows a message box with the problem and quits the program.
    void handleRunawayException(const QString &message);

Q_SIGNALS:
    void requestedInitialize();
    void requestedShutdown();
    void splashFinished();
    void windowShown(bitmonkeyGUI* window);

private:
    QThread *coreThread;
    interfaces::Node& m_node;
    OptionsModel *optionsModel;
    ClientModel *clientModel;
    bitmonkeyGUI *window;
    QTimer *pollShutdownTimer;
#ifdef ENABLE_WALLET
    PaymentServer* paymentServer{nullptr};
    WalletController* m_wallet_controller{nullptr};
#endif
    int returnValue;
    const PlatformStyle *platformStyle;
    std::unique_ptr<QWidget> shutdownWindow;

    void startThread();
};

int GuiMain(int argc, char* argv[]);

#endif // BITMONKEY_QT_BITMONKEY_H
