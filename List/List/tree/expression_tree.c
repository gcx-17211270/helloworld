#include "expression_tree.h"

/**
 * \function name create_expression_tree
 * \brief ������ʽ��.
 * \param tree   ���ʽ����ָ��
 * \param parent �Դ˽ڵ�Ϊ��������ʽ��
 * \param side  ��parent���ı߽ڵ㿪ʼ����
 * \param p     ��������ʽ
 * \param l     ���ʽ����
 * \return      ����ɹ��򷵻�TRUE�����򷵻�FALSE��tree��parent->children[side]֮�¼��ǹ���õı��ʽ��
 * 2020-11-14 November 
 */
bool create_expression_tree(BiTree* tree, BiTreeNode* parent, BiTreeNodeSide side, char* p, int l) {
    // lnum��¼"("��δ�ɶԸ�����
    // rpst1/rpst2��¼���ʽ��("*"��"/")/("+"��"-")��λ��;
    // pn��¼��������"."�ĸ���,���ж�����������Ƿ�Ϸ�
    int i = 0, lnum = 0, rpst1 = -1, rpst2 = -1, pn = 0;
    if (l == 0)
        return TRUE;
    //�жϱ��ʽ�Ƿ���ȷ
    if (*p == '+' || *p == '*' || *p == '/' || *p == '.' || *p == ')') {
        printf("Wrong expression��not start with number or left bracket!\n");
        return 0;
    }
    if (!(*(p + l - 1) == ')' || *(p + l - 1) >= '0' && *(p + l - 1) <= '9')) {
        printf("Wrong expression��not end with number or right bracket!\n");
        return 0;
    }
    if (*p == '(')
        lnum++;
    for (i = 1; i < l; i++) {
        if (*(p + i) == '.') {
            if (!(*(p + i - 1) >= '0' && *(p + i - 1) <= '9')) {
                printf("Wrong expression: no number following dot(.)!\n");
                return 0;
            }
        }
        else if (*(p + i) == '*' || *(p + i) == '/') {
            if (!(*(p + i - 1) >= '0' && *(p + i - 1) <= '9' || *(p + i - 1) == ')')) {
                printf("Wrong expression: not number or right bracket on the left of (*)!\n");
                return 0;
            }
            if (lnum == 0)
                rpst1 = i;
        }
        else if (*(p + i) == '(') {
            if (*(p + i - 1) == '+' || *(p + i - 1) == '-' || *(p + i - 1) == '*' || *(p + i - 1) == '/' || *(p + i - 1) == '(')
                lnum++;
            else {
                printf("Wrong expression: unexpected char appears on the left of left bracket!\n");
                return 0;
            }
        }
        else if (*(p + i) == ')') {
            if (*(p + i - 1) == ')' || *(p + i - 1) >= '0' && *(p + i - 1) <= '9')
                lnum--;
            else {
                printf("Wrong expression: unexpected char appears on the left of right bracket!\n");
                return 0;
            }
            if (lnum < 0) {
                printf("Wrong expression: left bracket and right bracket not equal!\n");
                return 0;
            }
        }
        else if (*(p + i) == '+' || *(p + i) == '-') {
            if (*(p + i) == '+' && !(*(p + i - 1) >= '0' && *(p + i - 1) <= '9' || *(p + i - 1) == ')')) {
                printf("Wrong expression: unexpected char appears on the left of (+)!\n");
                return 0;
            }
            else if (*(p + i) == '-' && !(*(p + i - 1) >= '0' && *(p + i - 1) <= '9' || *(p + i - 1) == ')' || *(p + i - 1) == '(')) {
                printf("Wrong expression: unexpected char appears on the left of (-)!\n");
                return 0;
            }
            if (lnum == 0)
                rpst2 = i;
        }
    }
    //"("��")"δ����ȫ���,���ʽ���벻�Ϸ�
    if (lnum != 0) {
        printf("Wrong expression�� left bracket and right bracket not equal!\n");
        return 0;
    }
    if (rpst2 > -1) {
        char* value = (char*)malloc(2 * sizeof(char));
        strncpy_s(value, 2, p+rpst2, 1);
        //strncpy(value, p + rpst2, 1);
        *(value + 1) = '\0';
        BiTreeNode* newNode = bitree_insert(tree, value, parent, side);
        if (create_expression_tree(tree, newNode, BITREE_NODE_LEFT, p, rpst2))
            if (create_expression_tree(tree, newNode, BITREE_NODE_RIGHT, p + rpst2 + 1, l - rpst2 - 1))
                return 1;
        return 0;
    }
    //��ʱ�������ʽ������һ�����֣����Ǳ��ʽ���屻һ������������
    if (rpst1 < 0) {
        if (*p == '(') { //��ʱ���ʽ���屻һ������������
            if (create_expression_tree(tree, parent, side, p + 1, l - 2))
                return 1;
            else
                return 0;
        }
        else {
            if (*(p + 1) != '(') {//��ʱ���ʽһ����һ������
                for (i = 0; i < l; i++) {
                    if (*(p + i) == '.')
                        pn++;
                    if (pn > 1) {
                        printf("Wrong expression: more than one dot(.) found in a number!\n");
                        return 0;
                    }
                }
                char* value = (char*)malloc((l + 1) * sizeof(char));
                strncpy_s(value, l + 1, p, l);
                //strncpy(value, p, l);
                *(value + l) = '\0';
                bitree_insert(tree, value, parent, side);
                return 1;
            }
            else {	//��ʱ���ʽ��һ���ǲ�����"-"�����ಿ�ֱ�һ������������
                char* value = (char*)malloc(2 * sizeof(char));
                strncpy_s(value, 2, p, 1);
                //strncpy(value, p, 1);
                *(value + 1) = '\0';
                BiTreeNode* newNode = bitree_insert(tree, value, parent, side);
                if (create_expression_tree(tree, newNode, BITREE_NODE_RIGHT, p + 2, l - 3))
                    return 1;
                else
                    return 0;
            }
        }
    }
    else {	//��ʱ�������ʽΪ����������˻��������ɵ�
        char* value = (char*)malloc(2 * sizeof(char));
        strncpy_s(value, 2, p + rpst2, 1);
        //strncpy(value, p + rpst1, 1);
        *(value + 1) = '\0';
        BiTreeNode* newNode = bitree_insert(tree, value, parent, side);
        if (create_expression_tree(tree, newNode, BITREE_NODE_LEFT, p, rpst1))
            if (create_expression_tree(tree, newNode, BITREE_NODE_RIGHT, p + rpst1 + 1, l - rpst1 - 1))
                return 1;
        return 0;
    }
}

int calculate(BiTreeNode* node, double* rst) {
    double l = 0, r = 0;//l��r�ֱ�������������������ֱ��ʽ��ֵ
    if (!node) {
        *rst = 0;
        return 1;
    }
    if (node->children[BITREE_NODE_LEFT] == NULL && node->children[BITREE_NODE_RIGHT] == NULL) {
        *rst = atof(node->value);
        return 1;
    }
    else {
        //�ȼ�����������������
        if (calculate(node->children[BITREE_NODE_LEFT], &l))
            if (calculate(node->children[BITREE_NODE_RIGHT], &r)) {
                switch (((char*)node->value)[0]) {
                case '+':
                    *rst = l + r;
                    break;
                case '-':
                    *rst = l - r;
                    break;
                case '*':
                    *rst = l * r;
                    break;
                case '/':
                    if (r == 0) {
                        printf("Divided by 0!\n");	//�澯,����Ϊ0
                        return 0;
                    }
                    else {
                        *rst = l / r;
                        break;
                    }
                default:
                    return 0;
                }
                return 1;
            }
        return 0;
    }
}

void create_expression_tree_callback(void) {
    char exp3[] = "-2+3/1.5-(10*3)+40";
    char exp4[] = "-(3+4*5)+1*2.5";
    double rst = 0;
    do_expression_calculate(exp3, &rst);
    printf(" = %.1f\n", rst);
    do_expression_calculate(exp4, &rst);
    printf(" = %.1f\n", rst);
}

void in_order_print(BiTreeNode* node) {}
void post_order_free(BiTreeNode* node) {}

int do_expression_calculate(char* exp, double* rst) {
    int l = strlen(exp);
    BiTree* tree = bitree_new();
    create_expression_tree(tree, tree->rootnode, BITREE_NODE_LEFT, exp, l);
    in_order_print(tree->rootnode);
    calculate(tree->rootnode, rst);
    post_order_free(tree->rootnode);
    bitree_free(tree);
}
