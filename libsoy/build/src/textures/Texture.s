
/* autogenerated from Texture.orc */

/* soy_textures_texture_surface2rgba */
.global soy_textures_texture_surface2rgba
.p2align 4
soy_textures_texture_surface2rgba:
# LOOP SHIFT 0
# LOOP SHIFT 1
# LOOP SHIFT 2
# LOOP SHIFT 3
# LOOP SHIFT 4
# LOOP SHIFT 4
# LOOP SHIFT 3
# LOOP SHIFT 2
# LOOP SHIFT 1
# LOOP SHIFT 0
  push %(null)
  movl 8(%esp), %ebp
  push %(null)
  movl 324(%ebp), %eax
  test %eax, %eax
  jle 5f
  movl %eax, 328(%ebp)
4:
  mov $16, %eax
  sub 20(%ebp), %eax
  and $15, %eax
  cmp %eax, 4(%ebp)
  jle 6f
  movl %eax, 8(%ebp)
  movl 4(%ebp), %ecx
  sub %eax, %ecx
  mov %ecx, %eax
  sar $5, %ecx
  movl %ecx, 12(%ebp)
  and $31, %eax
  movl %eax, 16(%ebp)
  jmp 7f
6:
  movl 4(%ebp), %eax
  movl %eax, 8(%ebp)
  mov $0, %eax
  movl %eax, 12(%ebp)
  movl %eax, 16(%ebp)
7:
  movl 20(%ebp), %eax
  movl 36(%ebp), %edx
  testl $1, 8(%ebp)
  jz 13f
13:
  testl $2, 8(%ebp)
  jz 14f
14:
  testl $4, 8(%ebp)
  jz 15f
15:
  testl $8, 8(%ebp)
  jz 16f
16:
1:
  cmp $0, 12(%ebp)
  jz 3f
  movl 12(%ebp), %esi
.p2align 4
2:
  add $-1, %esi
  jnz 2b
3:
  testl $16, 16(%ebp)
  jz 12f
12:
  testl $8, 16(%ebp)
  jz 11f
11:
  testl $4, 16(%ebp)
  jz 10f
10:
  testl $2, 16(%ebp)
  jz 9f
9:
  testl $1, 16(%ebp)
  jz 8f
8:
  movl 276(%ebp), %ecx
  add %ecx, 20(%ebp)
  movl 292(%ebp), %ecx
  add %ecx, 36(%ebp)
  add $-1, 328(%ebp)
  jnz 4b
5:
  pop %(null)
  pop %(null)
  ret 


