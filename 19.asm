;p183页，编程第四章习题： 19、21、24 (任选两题) 。要求如下：

;1、用MASM 6.15（M6）汇编、连接、用TD调试完成。
;2、建议：交视频（可附上word格式报告）；用屏幕录像的方式把调试过程做成视频文件-要有解说 （可参考资源包里的例子）。
;     对个别难以完成的同学，仅提交word报告也允许，但仅凭截图难以动态描述调试过程，可能会影响到所得成绩。
;19.试写出一段完整的数据段DATA_SEG，把整数5赋予一个字节，并把整数-1，0，2，5，4放在10字数组DATA_LIST的前5个单元中。
;然后，写出完整代码，其功能是把DATA_LIST中前5个数中的最大值和最小值分别存入到MAX和MIN单元中
DATA SEGMENT
	MESSAGE1 DB "the max number:","$"	;输出提示信息，0dh，0ah，回车换行
    MESSAGE2 DB 0DH,0AH,"the min number:","$"
    DATA_SEG DB 5
    DATA_LIST DB -1,0,2,5,4,5 DUP(?)
	max DB ?,'$'
	min db ?,'$'
DATA ENDS

STACK SEGMENT
	DW 100 DUP(?)
STACK ENDS

CODE SEGMENT
	ASSUME DS:DATA,CS:CODE,SS:STACK
START:
	MOV AX,DATA			;数据段载入
	MOV DS,AX
	LEA SI,DATA_LIST	;将数组用SI指针表示
	MOV CX,5
	MOV AL,[SI]
AGAIN:
	CMP AL,[SI]
	JG SMALL
	MOV AL,[SI]
SMALL:
	INC SI
	LOOP AGAIN
	
	ADD AL,30H
	MOV MAX,AL			;让ASCⅡ码保持在30H~39H

	MOV DX,OFFSET MESSAGE1
	MOV AH,09H
	INT 21H
	MOV DX,OFFSET MAX
	MOV AH,09H
	INT 21H
	
	LEA SI,DATA_LIST	;重复一遍比较出最小值
	MOV CX,5
	MOV AL,[SI]
AGAIN2:
	CMP AL,[SI]
	JNG BIG
	MOV AL,[SI]
BIG:
	INC SI
	LOOP AGAIN2
	
	ADD AL,30H
	MOV MIN,AL			;因为ASCⅡ码表无法显示-1，将会显示出29H的/

	MOV DX,OFFSET MESSAGE2
	MOV AH,09H
	INT 21H
	MOV DX,OFFSET MIN
	MOV AH,09H
	INT 21H

	MOV AH,4CH
	INT 21H
	
CODE ENDS
	END START


