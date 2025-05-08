#include <stdio.h>
#include <string.h>

// Ŀ�� �̵� �Լ�
void moveCursor(int y, int x) {
    printf("\033[%d;%dH", y, x);
}

// ������â �׸��� �Լ�
void drawConsoleWindow(int startX, int startY, int width, int height, const char* title) {
    int endX = startX + width - 1;
    int endY = startY + height - 1;

    printf("\033[43m");
    // 1. �׵θ� �׸���
    for (int x = startX; x <= endX; x++) {
        moveCursor(startY, x);   printf("-");  // ���
        moveCursor(endY, x);     printf("-");  // �ϴ�
    }

    for (int y = startY; y <= endY; y++) {
        moveCursor(y, startX);   printf("|");  // ����
        moveCursor(y, endX);     printf("|");  // ����
    }

    // 2. ���� ǥ���� ��� (�����)
    printf("\033[43m");  // ����: ���
    for (int x = startX + 1; x < endX; x++) {
        moveCursor(startY + 1, x);
        printf(" ");
    }

    // 3. ���� �ؽ�Ʈ
    moveCursor(startY + 1, startX + 2);
    printf("\033[1;30m%s\033[0m\033[43m", title); // ���� ���� �۾�

    // 4. �ݱ� ��ư "X" (�����ʿ��� 3��°)
    moveCursor(startY + 1, endX - 3);
    printf("\033[41;97mX\033[43m"); // ���� ��� + �� ����, �ڿ� ������� ����

    // 5. ���� ���� ä��� (�����)
    for (int y = startY + 2; y < endY; y++) {
        for (int x = startX + 1; x < endX; x++) {
            moveCursor(y, x);
            printf(" ");
        }
    }

    // ��Ÿ�� �ʱ�ȭ
    printf("\033[0m");
    moveCursor(endY + 1, 1);  // Ŀ�� �Ʒ��� �̵�
}

int main() {
    drawConsoleWindow(10, 3, 50, 15, "���� ���� ������");
    return 0;
}