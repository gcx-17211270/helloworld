;p183ҳ����̵�����ϰ�⣺ 19��21��24 (��ѡ����) ��Ҫ�����£�

;1����MASM 6.15��M6����ࡢ���ӡ���TD������ɡ�
;2�����飺����Ƶ���ɸ���word��ʽ���棩������Ļ¼��ķ�ʽ�ѵ��Թ���������Ƶ�ļ�-Ҫ�н�˵ ���ɲο���Դ��������ӣ���
;     �Ը���������ɵ�ͬѧ�����ύword����Ҳ��������ƾ��ͼ���Զ�̬�������Թ��̣����ܻ�Ӱ�쵽���óɼ���
;19.��д��һ�����������ݶ�DATA_SEG��������5����һ���ֽڣ���������-1��0��2��5��4����10������DATA_LIST��ǰ5����Ԫ�С�
;Ȼ��д���������룬�书���ǰ�DATA_LIST��ǰ5�����е����ֵ����Сֵ�ֱ���뵽MAX��MIN��Ԫ��
DATA SEGMENT
	MESSAGE1 DB "the max number:","$"	;�����ʾ��Ϣ��0dh��0ah���س�����
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
	MOV AX,DATA			;���ݶ�����
	MOV DS,AX
	LEA SI,DATA_LIST	;��������SIָ���ʾ
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
	MOV MAX,AL			;��ASC���뱣����30H~39H

	MOV DX,OFFSET MESSAGE1
	MOV AH,09H
	INT 21H
	MOV DX,OFFSET MAX
	MOV AH,09H
	INT 21H
	
	LEA SI,DATA_LIST	;�ظ�һ��Ƚϳ���Сֵ
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
	MOV MIN,AL			;��ΪASC������޷���ʾ-1��������ʾ��29H��/

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


