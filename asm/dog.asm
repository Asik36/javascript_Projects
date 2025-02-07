DATA Segment


ENDS DATA

Sseg Segment Stack

ENDS Sseg

CODE Segment
Assume cs:CODE, ds:DATA, ss:Sseg

start:
mov ax, DATA
mov ds, ax

mov di, 120
mov al, 10
mov cx,0
mov bx,0
x2:
add bx , [di]
add bx, [di+2]
cmp bx , [di]
js x1
inc cx
x1:
inc di
dec al
jne x2

mov ax, 4cH
int 21h
CODE ENDS
END start