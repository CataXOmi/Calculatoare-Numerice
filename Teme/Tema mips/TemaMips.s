.data
		matrice:	.word	-2 -3 14 11  0  5
					.word	3  6  2  1 -2  4
					.word	9 -1 10 10 12  3
					.word	1  4 -4  2  2 12
					.word	-3 13  9 -5 15  6
					.word	-2  1  9 14  1  7
		
		N:	.word	6	#numarul de linii sau coloane
		suma:	.word	0
		lungimeWord = 4	#valoare constanta de 4 octeti, in cazul unui double erau 8 octeti
		mesajsuma:	.asciiz "Suma elementelor de deasupra diagonalei principale este: "
.text
.globl main

main:
	la $a0, matrice	# retine prima adresa din matrice
	lw $a1, N
	jal sumDeasDiagPrin # apelam functia
	
	#Afiseaza mesaj
	li $v0, 4
	la $a0, mesajsuma
	syscall
	
	move $a0, $t0
	li $v0, 1	# afiseaza
	syscall
	
	li $v0, 10	# inchide programul
	syscall
.end main

.globl sumDeasDiagPrin

sumDeasDiagPrin:
	#suma = 0, t1 este i si se initializeaza cu 0 
	li $t0, 0 #suma = 0
	li $t1, 0 #i = 0
	
	bucla1 :
		mul $t2, $t1, $a1 #t2 = t1*a1
		add $t3, $t1, 1	# j = t1 + 1 = i + 1
	
	bucla2 :
		beq $t3, $a1, exit #if(j == N) EXIT
		add $t4, $t2, $t3 #t4 = t2 + t3 = t1*a1 + j = i*N + j
		mul $t4, $t4, lungimeWord #t4 = (i*N + j)*lungimeWord
		add $t4, $a0, $t4 #t4 contine adresa urmatorului element de pe linia respectiva, adica coloana urmatoare
		lw $t5, ($t4) #retinem valoarea de la adresa obtinuta
		add $t0, $t0, $t5 # adauga valoarea noua la suma
		add $t3, $t3, 1 # incrementam j
		blt $t3, $a1, bucla2 # if(j < N) apeleaza bucla2
	
	exit :
		add $t1, $t1, 1 # incrementam i
		blt $t1, $a1, bucla1 # if(i < N) apeleaza bucla1
	jr $ra # revine din functiei 
.end sumDeasDiagPrin