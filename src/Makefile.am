# Copyright (c) 2013-2016 The bitmonkey Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS) $(GPROF_LDFLAGS) $(SANITIZER_LDFLAGS)
AM_CXXFLAGS = $(DEBUG_CXXFLAGS) $(HARDENED_CXXFLAGS) $(WARN_CXXFLAGS) $(NOWARN_CXXFLAGS) $(ERROR_CXXFLAGS) $(GPROF_CXXFLAGS) $(SANITIZER_CXXFLAGS)
AM_CPPFLAGS = $(DEBUG_CPPFLAGS) $(HARDENED_CPPFLAGS)
AM_LIBTOOLFLAGS = --preserve-dup-deps
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

BITMONKEY_INCLUDES=-I$(builddir) $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

BITMONKEY_INCLUDES += -I$(srcdir)/secp256k1/include
BITMONKEY_INCLUDES += $(UNIVALUE_CFLAGS)

LIBBITMONKEY_SERVER=libbitmonkey_server.a
LIBBITMONKEY_COMMON=libbitmonkey_common.a
LIBBITMONKEY_CONSENSUS=libbitmonkey_consensus.a
LIBBITMONKEY_CLI=libbitmonkey_cli.a
LIBBITMONKEY_UTIL=libbitmonkey_util.a
LIBBITMONKEY_CRYPTO_BASE=crypto/libbitmonkey_crypto_base.a
LIBBITMONKEYQT=qt/libbitmonkeyqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBBITMONKEY_ZMQ=libbitmonkey_zmq.a
endif
if BUILD_BITMONKEY_LIBS
LIBBITMONKEYCONSENSUS=libbitmonkeyconsensus.la
endif
if ENABLE_WALLET
LIBBITMONKEY_WALLET=libbitmonkey_wallet.a
LIBBITMONKEY_WALLET_TOOL=libbitmonkey_wallet_tool.a
endif

LIBBITMONKEY_CRYPTO= $(LIBBITMONKEY_CRYPTO_BASE)
if ENABLE_SSE41
LIBBITMONKEY_CRYPTO_SSE41 = crypto/libbitmonkey_crypto_sse41.a
LIBBITMONKEY_CRYPTO += $(LIBBITMONKEY_CRYPTO_SSE41)
endif
if ENABLE_AVX2
LIBBITMONKEY_CRYPTO_AVX2 = crypto/libbitmonkey_crypto_avx2.a
LIBBITMONKEY_CRYPTO += $(LIBBITMONKEY_CRYPTO_AVX2)
endif
if ENABLE_SHANI
LIBBITMONKEY_CRYPTO_SHANI = crypto/libbitmonkey_crypto_shani.a
LIBBITMONKEY_CRYPTO += $(LIBBITMONKEY_CRYPTO_SHANI)
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*.h) $(wildcard secp256k1/src/*.c) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBBITMONKEY_CRYPTO) \
  $(LIBBITMONKEY_UTIL) \
  $(LIBBITMONKEY_COMMON) \
  $(LIBBITMONKEY_CONSENSUS) \
  $(LIBBITMONKEY_SERVER) \
  $(LIBBITMONKEY_CLI) \
  $(LIBBITMONKEY_WALLET) \
  $(LIBBITMONKEY_WALLET_TOOL) \
  $(LIBBITMONKEY_ZMQ)

lib_LTLIBRARIES = $(LIBBITMONKEYCONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_BITMONKEYD
  bin_PROGRAMS += bitmonkeyd
endif

if BUILD_BITMONKEY_CLI
  bin_PROGRAMS += bitmonkey-cli
endif
if BUILD_BITMONKEY_TX
  bin_PROGRAMS += bitmonkey-tx
endif
if ENABLE_WALLET
if BUILD_BITMONKEY_WALLET
  bin_PROGRAMS += bitmonkey-wallet
endif
endif

.PHONY: FORCE check-symbols check-security
# bitmonkey core #
BITMONKEY_CORE_H = \
  addrdb.h \
  addrman.h \
  attributes.h \
  banman.h \
  base58.h \
  bech32.h \
  bloom.h \
  blockencodings.h \
  blockfilter.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  compat.h \
  compat/assumptions.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_check.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  flatfile.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  index/base.h \
  index/blockfilterindex.h \
  index/txindex.h \
  indirectmap.h \
  init.h \
  interfaces/chain.h \
  interfaces/handler.h \
  interfaces/node.h \
  interfaces/wallet.h \
  key.h \
  key_io.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  logging.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  net_processing.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  node/coin.h \
  node/psbt.h \
  node/transaction.h \
  noui.h \
  optional.h \
  outputtype.h \
  policy/feerate.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
  policy/settings.h \
  pow.h \
  protocol.h \
  psbt.h \
  random.h \
  reverse_iterator.h \
  reverselock.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/rawtransaction_util.h \
  rpc/register.h \
  rpc/util.h \
  scheduler.h \
  script/descriptor.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  shutdown.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadsafety.h \
  threadinterrupt.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  undo.h \
  util/bip32.h \
  util/bytevectorhash.h \
  util/error.h \
  util/fees.h \
  util/system.h \
  util/memory.h \
  util/moneystr.h \
  util/rbf.h \
  util/threadnames.h \
  util/time.h \
  util/url.h \
  util/validation.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  versionbitsinfo.h \
  walletinitinterface.h \
  wallet/coincontrol.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/ismine.h \
  wallet/load.h \
  wallet/psbtwallet.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  wallet/wallettool.h \
  wallet/walletutil.h \
  wallet/coinselection.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  zmq/zmqrpc.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
libbitmonkey_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between bitmonkeyd and bitmonkey-qt
# Contains code accessing mempool and chain state that is meant to be separated
# from wallet and gui code (see node/README.md). Shared code should go in
# libbitmonkey_common or libbitmonkey_util libraries, instead.
libbitmonkey_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libbitmonkey_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_server_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  banman.cpp \
  blockencodings.cpp \
  blockfilter.cpp \
  chain.cpp \
  consensus/tx_verify.cpp \
  flatfile.cpp \
  httprpc.cpp \
  httpserver.cpp \
  index/base.cpp \
  index/blockfilterindex.cpp \
  index/txindex.cpp \
  interfaces/chain.cpp \
  interfaces/node.cpp \
  init.cpp \
  dbwrapper.cpp \
  miner.cpp \
  net.cpp \
  net_processing.cpp \
  node/coin.cpp \
  node/psbt.cpp \
  node/transaction.cpp \
  noui.cpp \
  policy/fees.cpp \
  policy/rbf.cpp \
  policy/settings.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  script/sigcache.cpp \
  shutdown.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  ui_interface.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(BITMONKEY_CORE_H)

if ENABLE_WALLET
libbitmonkey_server_a_SOURCES += wallet/init.cpp
endif
if !ENABLE_WALLET
libbitmonkey_server_a_SOURCES += dummywallet.cpp
endif

if ENABLE_ZMQ
libbitmonkey_zmq_a_CPPFLAGS = $(BITMONKEY_INCLUDES) $(ZMQ_CFLAGS)
libbitmonkey_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp \
  zmq/zmqrpc.cpp
endif


# wallet: shared between bitmonkeyd and bitmonkey-qt, but only linked
# when wallet enabled
libbitmonkey_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
libbitmonkey_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_wallet_a_SOURCES = \
  interfaces/wallet.cpp \
  wallet/coincontrol.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/ismine.cpp \
  wallet/load.cpp \
  wallet/psbtwallet.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  wallet/walletutil.cpp \
  wallet/coinselection.cpp \
  $(BITMONKEY_CORE_H)

libbitmonkey_wallet_tool_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
libbitmonkey_wallet_tool_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_wallet_tool_a_SOURCES = \
  wallet/wallettool.cpp \
  $(BITMONKEY_CORE_H)

# crypto primitives library
crypto_libbitmonkey_crypto_base_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitmonkey_crypto_base_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitmonkey_crypto_base_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha20.h \
  crypto/chacha20.cpp \
  crypto/common.h \
  crypto/hkdf_sha256_32.cpp \
  crypto/hkdf_sha256_32.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/poly1305.h \
  crypto/poly1305.cpp \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h \
  crypto/siphash.cpp \
  crypto/siphash.h

if USE_ASM
crypto_libbitmonkey_crypto_base_a_SOURCES += crypto/sha256_sse4.cpp
endif

crypto_libbitmonkey_crypto_sse41_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitmonkey_crypto_sse41_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitmonkey_crypto_sse41_a_CXXFLAGS += $(SSE41_CXXFLAGS)
crypto_libbitmonkey_crypto_sse41_a_CPPFLAGS += -DENABLE_SSE41
crypto_libbitmonkey_crypto_sse41_a_SOURCES = crypto/sha256_sse41.cpp

crypto_libbitmonkey_crypto_avx2_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitmonkey_crypto_avx2_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitmonkey_crypto_avx2_a_CXXFLAGS += $(AVX2_CXXFLAGS)
crypto_libbitmonkey_crypto_avx2_a_CPPFLAGS += -DENABLE_AVX2
crypto_libbitmonkey_crypto_avx2_a_SOURCES = crypto/sha256_avx2.cpp

crypto_libbitmonkey_crypto_shani_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitmonkey_crypto_shani_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitmonkey_crypto_shani_a_CXXFLAGS += $(SHANI_CXXFLAGS)
crypto_libbitmonkey_crypto_shani_a_CPPFLAGS += -DENABLE_SHANI
crypto_libbitmonkey_crypto_shani_a_SOURCES = crypto/sha256_shani.cpp

# consensus: shared between all executables that validate any consensus rules.
libbitmonkey_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
libbitmonkey_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/tx_check.cpp \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/bitmonkeyconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  span.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  util/strencodings.cpp \
  util/strencodings.h \
  version.h

# common: shared between bitmonkeyd, and bitmonkey-qt and non-server tools
libbitmonkey_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
libbitmonkey_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_common_a_SOURCES = \
  base58.cpp \
  bech32.cpp \
  bloom.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  key_io.cpp \
  keystore.cpp \
  merkleblock.cpp \
  netaddress.cpp \
  netbase.cpp \
  outputtype.cpp \
  policy/feerate.cpp \
  policy/policy.cpp \
  protocol.cpp \
  psbt.cpp \
  rpc/rawtransaction_util.cpp \
  rpc/util.cpp \
  scheduler.cpp \
  script/descriptor.cpp \
  script/sign.cpp \
  script/standard.cpp \
  versionbitsinfo.cpp \
  warnings.cpp \
  $(BITMONKEY_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libbitmonkey_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
libbitmonkey_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  interfaces/handler.cpp \
  logging.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util/bip32.cpp \
  util/bytevectorhash.cpp \
  util/error.cpp \
  util/fees.cpp \
  util/system.cpp \
  util/moneystr.cpp \
  util/rbf.cpp \
  util/threadnames.cpp \
  util/strencodings.cpp \
  util/time.cpp \
  util/url.cpp \
  util/validation.cpp \
  $(BITMONKEY_CORE_H)

if GLIBC_BACK_COMPAT
libbitmonkey_util_a_SOURCES += compat/glibc_compat.cpp
AM_LDFLAGS += $(COMPAT_LDFLAGS)
endif

# cli: shared between bitmonkey-cli and bitmonkey-qt
libbitmonkey_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
libbitmonkey_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitmonkey_cli_a_SOURCES = \
  rpc/client.cpp \
  $(BITMONKEY_CORE_H)

nodist_libbitmonkey_util_a_SOURCES = $(srcdir)/obj/build.h
#

# bitmonkeyd binary #
bitmonkeyd_SOURCES = bitmonkeyd.cpp
bitmonkeyd_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
bitmonkeyd_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitmonkeyd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitmonkeyd_SOURCES += bitmonkeyd-res.rc
endif

# Libraries below may be listed more than once to resolve circular dependencies (see
# https://eli.thegreenplace.net/2013/07/09/library-order-in-static-linking#circular-dependency)
bitmonkeyd_LDADD = \
  $(LIBBITMONKEY_SERVER) \
  $(LIBBITMONKEY_WALLET) \
  $(LIBBITMONKEY_SERVER) \
  $(LIBBITMONKEY_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBBITMONKEY_UTIL) \
  $(LIBBITMONKEY_ZMQ) \
  $(LIBBITMONKEY_CONSENSUS) \
  $(LIBBITMONKEY_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

bitmonkeyd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# bitmonkey-cli binary #
bitmonkey_cli_SOURCES = bitmonkey-cli.cpp
bitmonkey_cli_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES) $(EVENT_CFLAGS)
bitmonkey_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitmonkey_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitmonkey_cli_SOURCES += bitmonkey-cli-res.rc
endif

bitmonkey_cli_LDADD = \
  $(LIBBITMONKEY_CLI) \
  $(LIBUNIVALUE) \
  $(LIBBITMONKEY_UTIL) \
  $(LIBBITMONKEY_CRYPTO)

bitmonkey_cli_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# bitmonkey-tx binary #
bitmonkey_tx_SOURCES = bitmonkey-tx.cpp
bitmonkey_tx_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
bitmonkey_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitmonkey_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitmonkey_tx_SOURCES += bitmonkey-tx-res.rc
endif

bitmonkey_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBBITMONKEY_COMMON) \
  $(LIBBITMONKEY_UTIL) \
  $(LIBBITMONKEY_CONSENSUS) \
  $(LIBBITMONKEY_CRYPTO) \
  $(LIBSECP256K1)

bitmonkey_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# bitmonkey-wallet binary #
bitmonkey_wallet_SOURCES = bitmonkey-wallet.cpp
bitmonkey_wallet_CPPFLAGS = $(AM_CPPFLAGS) $(BITMONKEY_INCLUDES)
bitmonkey_wallet_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitmonkey_wallet_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitmonkey_wallet_SOURCES += bitmonkey-wallet-res.rc
endif

bitmonkey_wallet_LDADD = \
  $(LIBBITMONKEY_WALLET_TOOL) \
  $(LIBBITMONKEY_WALLET) \
  $(LIBBITMONKEY_COMMON) \
  $(LIBBITMONKEY_CONSENSUS) \
  $(LIBBITMONKEY_UTIL) \
  $(LIBBITMONKEY_CRYPTO) \
  $(LIBBITMONKEY_ZMQ) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1) \
  $(LIBUNIVALUE)

bitmonkey_wallet_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(CRYPTO_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(MINIUPNPC_LIBS) $(ZMQ_LIBS)
#

# bitmonkeyconsensus library #
if BUILD_BITMONKEY_LIBS
include_HEADERS = script/bitmonkeyconsensus.h
libbitmonkeyconsensus_la_SOURCES = $(crypto_libbitmonkey_crypto_base_a_SOURCES) $(libbitmonkey_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  libbitmonkeyconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libbitmonkeyconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
libbitmonkeyconsensus_la_LIBADD = $(LIBSECP256K1)
libbitmonkeyconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_BITMONKEY_INTERNAL
libbitmonkeyconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/bitmonkey-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/bitmonkey-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/bitmonkey-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/bitmonkey-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(PYTHON) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(PYTHON) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

if ENABLE_BIP70
%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<
endif

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
