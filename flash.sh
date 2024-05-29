#!/bin/bash
qmk compile || exit
sudo mount /dev/sda ~/mnt || exit
sudo mv ./ymdk_id75_elekrisk.uf2 ~/mnt
sudo umount ~/mnt
