#include <stdio.h>


// Ŀ�� �̵�
void moveCursor(int y, int x) {
    printf("\033[%d;%dH", y, x);
}

// ������â ��� �Լ�
void drawWindow(int startX, int startY, int width, int height) {
    int endX = startX + width - 1;
    int endY = startY + height - 1;

    // ��� �� ���� (�Ķ� ���)
    printf("\033[44m");

    // ������ ��� ���� ä���
    for (int y = startY + 1; y < endY; y++) {
        for (int x = startX + 1; x < endX; x++) {
            moveCursor(y, x);
            printf(" ");
        }
    }

    // �׵θ� �׸���
    for (int x = startX; x <= endX; x++) {
        moveCursor(startY, x); printf("-");
        moveCursor(endY, x);   printf("-");
    }

    for (int y = startY; y <= endY; y++) {
        moveCursor(y, startX); printf("|");
        moveCursor(y, endX);   printf("|");
    }

    // ������
    moveCursor(startY, startX);     printf("+");
    moveCursor(startY, endX);       printf("+");
    moveCursor(endY, startX);       printf("+");
    moveCursor(endY, endX);         printf("+");

    // �ݱ� ��ư (���� ���)
    moveCursor(startY, endX - 2);
    printf("\033[41;97mX\033[44m"); // ���� ��� + �� ����

    // �ʱ�ȭ �� Ŀ�� �Ʒ��� �̵�
    printf("\033[0m");
    moveCursor(endY + 1, 1);
}

int main() {
    int width = 80;   // �ܼ� ����
    int height = 25;  // �ܼ� ����

    int top_margin = 1;
    int bottom_margin = 1;
    int left_margin = 2;
    int right_margin = 2;

    // �Ķ� ������� ���� ���� ä���
    printf("\033[44m");  // �Ķ��� ���
    for (int row = top_margin + 1; row <= height - bottom_margin; row++) {
        for (int col = left_margin + 1; col <= width - right_margin; col++) {
            printf("\033[%d;%dH ", row, col);  // Ŀ�� �̵� + ���� ���
        }
    }

    // �� �Ʒ����� ȸ�� ������� ����
    printf("\033[100m");  // ȸ�� ���
    int row = height;     // ������ ��
    for (int col = 3; col < width-1; col++) {
        printf("\033[%d;%dH ", row, col);
    }

    // ��Ÿ�� �ʱ�ȭ + Ŀ�� �Ʒ��� ������
    printf("\033[0m\033[%d;1H", height + 1);

    return 0;
}