#!/bin/bash
qmk compile
if uname -a | grep WSL
then
  if [ -d /mnt/g ]
  then
    echo "G: already mounted"
    exit
  fi
  sudo mkdir -p /mnt/g
  until sudo mount -t drvfs G: /mnt/g
  do
    sleep 1
  done
  sudo cp keebio_iris_ce_rev1_elekrisk.uf2 /mnt/g/
  sudo umount /mnt/g
  sudo rmdir /mnt/g
fi
