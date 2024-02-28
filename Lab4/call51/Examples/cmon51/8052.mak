#
# cmon51 8052.mak
#

CC = c51
LL = c51
PACK = packihx

OBJS= 8052.obj cmon51.obj d51.obj step.obj

8052.hex: $(OBJS)
	$(LL) --code-size 0x2000 --xram-loc 0x1f00 --xram-size 0x100 $(OBJS)

8052.obj: 8052.c 8052.mak
	$(CC) -c -DSFR_CODE_LOC=0x7ff8 -DXRAM_CODE_LOC=0x2000 8052.c

cmon51.obj: cmon51.c cmon51.h d51.h 8052.mak
	$(CC) -c cmon51.c

d51.obj: d51.c d51.h 8052.mak
	$(CC) -c d51.c

step.obj: step.c 8052.mak
	$(CC) -c step.c
