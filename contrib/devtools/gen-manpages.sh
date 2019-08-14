#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BITMONKEYD=${BITMONKEYD:-$BINDIR/bitmonkeyd}
BITMONKEYCLI=${BITMONKEYCLI:-$BINDIR/bitmonkey-cli}
BITMONKEYTX=${BITMONKEYTX:-$BINDIR/bitmonkey-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/bitmonkey-wallet}
BITMONKEYQT=${BITMONKEYQT:-$BINDIR/qt/bitmonkey-qt}

[ ! -x $BITMONKEYD ] && echo "$BITMONKEYD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTMVER=($($BITMONKEYCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for bitmonkeyd if --version-string is not set,
# but has different outcomes for bitmonkey-qt and bitmonkey-cli.
echo "[COPYRIGHT]" > footer.h2m
$BITMONKEYD --version | sed -n '1!p' >> footer.h2m

for cmd in $BITMONKEYD $BITMONKEYCLI $BITMONKEYTX $WALLET_TOOL $BITMONKEYQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTMVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTMVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
