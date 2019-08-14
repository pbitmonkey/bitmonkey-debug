// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The bitmonkey Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITMONKEY_UTIL_FEES_H
#define BITMONKEY_UTIL_FEES_H

#include <string>

enum class FeeEstimateMode;
enum class FeeReason;

bool FeeModeFromString(const std::string& mode_string, FeeEstimateMode& fee_estimate_mode);
std::string StringForFeeReason(FeeReason reason);

#endif // BITMONKEY_UTIL_FEES_H
