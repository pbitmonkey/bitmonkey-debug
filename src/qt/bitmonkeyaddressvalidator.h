// Copyright (c) 2011-2014 The bitmonkey Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITMONKEY_QT_BITMONKEYADDRESSVALIDATOR_H
#define BITMONKEY_QT_BITMONKEYADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class bitmonkeyAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit bitmonkeyAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** bitmonkey address widget validator, checks for a valid bitmonkey address.
 */
class bitmonkeyAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit bitmonkeyAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITMONKEY_QT_BITMONKEYADDRESSVALIDATOR_H
