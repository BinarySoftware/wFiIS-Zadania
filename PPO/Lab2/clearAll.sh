#!/bin/bash
read -p "Usunac wszystko? (T/N): " confirm
shopt -s extglob;
if [ "$confirm" = "T" ]; then
  rm -rv !("clearAll.sh");
fi