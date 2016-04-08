Howto: Dual-Boot NetBSD
=======================

It is described here, how to dual boot NetBSD with another operating system installed previously, or to be installed after NetBSD.


Create backup for your data
---------------------------

It is important to backup your files to an external backup medium before attempting a dual-boot install (or partitioning), in case your hard drive corrupts, it will result in loss of data. DVD/CD, External hard drive, pen-drives, or cloud sync services are suitable for this purpose.


Install Linux/Windows/Unix with NetBSD
--------------------------------------

### Install NetBSD after another operating system

1. Download the .iso file for your hardware architecture and burn it to a CD or DVD.
2. Insert the LiveCD into your CD-ROM drive and reboot your PC.
3. If the computer does not boot from the CD (e.g. Linux starts again instead), reboot and check your BIOS settings by pressing F2, F12, Delete, or ESC. Select "boot from CD".
4. Proceed with installation.
5. If you have already partitioned the disk and left space for NetBSD, install it to that and then follow the rest of the steps.
6. Otherwise, partition the disk first. (can be done using fdisk from Linux/Unix, or the partition manager in Windows)

Here NetBSD is sharing a hard disk with another operating system.
You will want to install a boot manager, i.e., a program which lets you choose which OS to start at boot time. sysinst can do this for you and will ask if you want to install one. Or you can manually install your preferable boot manager.

    
### Install another operating system after NetBSD

1. It is recommended that you partition your hard drive, before starting the installation, through NetBSD. Otherwise, you can use the partitioning tool of the operating system you are going to install. You may even need to resize your current NetBSD partition, so ensure that you have a backup of your data.
2. Install the other OS in the newly made partition.
3. While installing the other operating system, you may have installed a new bootloader. Generally various boot managers identify NetBSD automatically, still if you prefer you can re-install your favorite bootloader from NetBSD, and add the new OS in the list.
4. If the new os is linux, and it automatically installed grub2 bootloader, you can add NetBSD to the grub list by adding the following in /etc/grub.d/40_custom
```
menuentry "NetBSD on sda1" {
insmod ufs2
set root=(hd0,msdos1)
knetbsd /netbsd --root=wd0a
}
```

replace "ufs2", "wd0a" and "(hd0,msdos1)", with your configuration.
5. You can also configure NetBSD's internal bootloader, to boot the other operating system. If the new operating system installed its own bootloader on the hard drive just use <code>fdisk -u wd0</code> through root (replace "wd0" with your config), to install NetBSD's bootloader back, and to edit the partition table accordingly. Note: Sometimes, NetBSD's bootloader gives "Error 3" when you try booting a linux partition. In this case you may try using a different bootloader.