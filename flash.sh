#!/bin/bash
qmk compile || exit
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
else
  if [ -d /mnt/keeb ]
  then
    echo "G: already mounted"
    exit
  fi
  sudo mkdir -p /mnt/keeb
  until sudo mount /dev/sda1 /mnt/keeb
  do
    sleep 1
  done
  
  sudo cp keebio_iris_ce_rev1_elekrisk.uf2 /mnt/keeb/
  sudo umount /mnt/keeb
  sudo rmdir /mnt/keeb
fi
