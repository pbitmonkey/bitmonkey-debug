#!/usr/bin/env bash
#
# Copyright (c) 2018 The bitmonkey Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
#
# Check for circular dependencies

export LC_ALL=C

EXPECTED_CIRCULAR_DEPENDENCIES=(
    "chainparamsbase -> util/system -> chainparamsbase"
    "index/txindex -> validation -> index/txindex"
    "policy/fees -> txmempool -> policy/fees"
    "qt/addresstablemodel -> qt/walletmodel -> qt/addresstablemodel"
    "qt/bantablemodel -> qt/clientmodel -> qt/bantablemodel"
    "qt/bitmonkeygui -> qt/utilitydialog -> qt/bitmonkeygui"
    "qt/bitmonkeygui -> qt/walletframe -> qt/bitmonkeygui"
    "qt/bitmonkeygui -> qt/walletview -> qt/bitmonkeygui"
    "qt/clientmodel -> qt/peertablemodel -> qt/clientmodel"
    "qt/paymentserver -> qt/walletmodel -> qt/paymentserver"
    "qt/recentrequeststablemodel -> qt/walletmodel -> qt/recentrequeststablemodel"
    "qt/sendcoinsdialog -> qt/walletmodel -> qt/sendcoinsdialog"
    "qt/transactiontablemodel -> qt/walletmodel -> qt/transactiontablemodel"
    "qt/walletmodel -> qt/walletmodeltransaction -> qt/walletmodel"
    "txmempool -> validation -> txmempool"
    "wallet/coincontrol -> wallet/wallet -> wallet/coincontrol"
    "wallet/fees -> wallet/wallet -> wallet/fees"
    "wallet/wallet -> wallet/walletdb -> wallet/wallet"
    "policy/fees -> txmempool -> validation -> policy/fees"
    "qt/guiutil -> qt/walletmodel -> qt/optionsmodel -> qt/guiutil"
    "txmempool -> validation -> validationinterface -> txmempool"
    "wallet/ismine -> wallet/wallet -> wallet/ismine"
)

EXIT_CODE=0

CIRCULAR_DEPENDENCIES=()

IFS=$'\n'
for CIRC in $(cd src && ../contrib/devtools/circular-dependencies.py {*,*/*,*/*/*}.{h,cpp} | sed -e 's/^Circular dependency: //'); do
    CIRCULAR_DEPENDENCIES+=($CIRC)
    IS_EXPECTED_CIRC=0
    for EXPECTED_CIRC in "${EXPECTED_CIRCULAR_DEPENDENCIES[@]}"; do
        if [[ "${CIRC}" == "${EXPECTED_CIRC}" ]]; then
            IS_EXPECTED_CIRC=1
            break
        fi
    done
    if [[ ${IS_EXPECTED_CIRC} == 0 ]]; then
        echo "A new circular dependency in the form of \"${CIRC}\" appears to have been introduced."
        echo
        EXIT_CODE=1
    fi
done

for EXPECTED_CIRC in "${EXPECTED_CIRCULAR_DEPENDENCIES[@]}"; do
    IS_PRESENT_EXPECTED_CIRC=0
    for CIRC in "${CIRCULAR_DEPENDENCIES[@]}"; do
        if [[ "${CIRC}" == "${EXPECTED_CIRC}" ]]; then
            IS_PRESENT_EXPECTED_CIRC=1
            break
        fi
    done
    if [[ ${IS_PRESENT_EXPECTED_CIRC} == 0 ]]; then
        echo "Good job! The circular dependency \"${EXPECTED_CIRC}\" is no longer present."
        echo "Please remove it from EXPECTED_CIRCULAR_DEPENDENCIES in $0"
        echo "to make sure this circular dependency is not accidentally reintroduced."
        echo
        EXIT_CODE=1
    fi
done

exit ${EXIT_CODE}
