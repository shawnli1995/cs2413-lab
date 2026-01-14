#!/usr/bin/env bash
set -euo pipefail

echo "=== Two Sum Lab: Running Tests ==="
date
echo

make clean >/dev/null 2>&1 || true
make test
