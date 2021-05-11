redrawScreen:
	.word 1

changingColor4:
	.word COLOR_BLUE
	
coordinates_x:
	.word 5

count:
	.word 0

state:
	.word 1

	.text
jt:
	.word default
	.word option1
	.word option2
	.word option3

	.global wdt_c_handler
wdt_c_handler:
	;;start counter
	add #1, &count
	;; range check on state variable
	cmp #2, &state
	jlo option1

	;;index into jump table

	mov &state, r12
	mov jt(r12), r0
	;;switch table options
option1:jz count
	mov #5, r12
	;; coordinates line needed
	;; changingColor4 line needed
	mov #changingColor4, r12
	mov.b r12,
	
	mov #1, &redrawScreen
option2:jz count
	mov #100, r12
	;; coordinates line needed
	;; changingColor4 line needed
	mov #1, &redrawScreen
	
option3:jz count
	mov #250, r12
	mov #0, &count
	;; coordinates line needed
	;; changingColor4 line needed
	mov #1, &redrawScreen
	mov #1, &state
	jmp end
	
default:mov #0, &count
	mov #1, &state

end:	pop r0
	

	
