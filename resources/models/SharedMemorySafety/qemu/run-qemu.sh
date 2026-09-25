#!/bin/bash
# QEMU test for SharedMemorySafety-design.md stages 2, 4 and 5, run by
# SharedMemorySafetyQemuTests against HAMR's Microkit output for models/SharedMemorySafety.
#
# usage: run-qemu.sh <microkit-output-dir> <seconds> <log>
#
# Installs the test's producer (C) and consumer (Rust) behaviour code into the generated
# system, builds it (including Verus), boots it under QEMU for <seconds>, and writes the
# console to <log>.  The producer sends valid messages, then corrupted ones, then writes past
# its region; the consumer checks and logs everything it receives.  The test reads the log.
set -u
dir=$1; secs=$2; log=$3
here=$(cd "$(dirname "$0")" && pwd)

cp "$here/producer_p_producer_user.c" "$dir/components/producer_p_producer/src/" || exit 2
cp "$here/consumer_p_consumer_app.rs" "$dir/crates/consumer_p_consumer/src/component/" || exit 2

cd "$dir" || exit 2
make > "$log.build" 2>&1 || { echo "BUILD FAILED (see $log.build)"; tail -30 "$log.build"; exit 1; }

# run QEMU in its own process group so that exactly it, and nothing else on the machine,
# is stopped afterwards
set -m
make qemu > "$log" 2>&1 &
pid=$!
set +m
sleep "$secs"
kill -TERM -- "-$pid" 2>/dev/null
wait "$pid" 2>/dev/null
exit 0
