// Copyright (c) 2019 The bitmonkey Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITMONKEY_NODE_COIN_H
#define BITMONKEY_NODE_COIN_H

#include <map>

class COutPoint;
class Coin;

/**
 * Look up unspent output information. Returns coins in the mempool and in the
 * current chain UTXO set. Iterates through all the keys in the map and
 * populates the values.
 *
 * @param[in,out] coins map to fill
 */
void FindCoins(std::map<COutPoint, Coin>& coins);

#endif // BITMONKEY_NODE_COIN_H
