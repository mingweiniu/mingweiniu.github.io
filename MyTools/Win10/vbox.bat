

cd "C:\Program Files\Oracle\VirtualBox\"
REM copy as .vdi
 ./vboxmanage clonemedium disk D:\Image.vmdk D:\Image.vdi --format VDI
REM shrink it
 ./vboxmanage modifymedium D:\Image.vdi --compact


VBoxManage clonehd --format VDI old.vmdk new.vdi
VBoxmanage modifyhd old.vdi --resize 100000
