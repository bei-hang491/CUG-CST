#define NDEBUG
#include <GL/glut.h>

#include <iostream>

void MidBresehamLine(int x0, int y0, int x1, int y1) {
    int dx, dy, d, UpIncre, DownIncre, x, y;
    if (x0 > x1) {  //������0�͵�1��λ��
        x = x1, x1 = x0, x0 = x;
        y = y1, y1 = y0, y0 = y;
    }
    x = x0;
    y = y0;        //�ӵ�0��ʼģ��ֱ��
    dx = x1 - x0;  // x������
    dy = y1 - y0;  // y������

    if (abs(dy) > abs(dx)) {  //�ж�б�ʵľ���ֵ�Ƿ����1
        //����2*dy����ֹ���ָ�����
        d = dy - 2 * dx;            //��ʼλ�ã�d0=2*dy*(0.5-(1/k))
        UpIncre = 2 * dy - 2 * dx;  //��������: UpIncre=2*dy*(1-(1/k))
        DownIncre = 2 * dx;         //��������: DownIncre=2*dy*(1/k)
        while (y <= y1) {           //С�ڵ���y1ʱ
            std::cout << "  x: " << x << "  y: " << y
                      << std::endl;  //����õ�����λ��
            y++;                     // y��������1
            if (d < 0) {  //���d<0�����е�λ����ֱ���·�����ѡȡ��x+1,y+1��
                          //ͬʱ����d
                x++;
                d += UpIncre;
            } else {  //���d>0�����е�λ����ֱ���Ϸ�����ѡȡ��x,y+1�� ͬʱ����d
                d -= DownIncre;
            }
        }
    } else {
        //����2*dx����ֹ���ָ�����
        d = dx - 2 * dy;            //��ʼλ�ã�d=2*dx*��0.5-2k��
        UpIncre = 2 * dx - 2 * dy;  //��������: UpIncre=2*dx*(1-k)
        DownIncre = 2 * dy;         //��������: DownIncre=2*dx*k

        while (x <= x1) {  //С�ڵ���x1ʱ
            std::cout << "  x: " << x << "  y: " << y
                      << std::endl;  //����õ�����λ��
            x++;                     // x��������1
            if (d < 0) {  //���d<0�����е�λ����ֱ���·�����ѡȡ��x+1,y+1��
                          //ͬʱ����d
                y++;
                d += UpIncre;
            } else {  //���d>0�����е�λ����ֱ���Ϸ�����ѡȡ��x+1,y�� ͬʱ����d
                d -= DownIncre;
            }
        }
    }
}

void MidBresehamCircle() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(1.0);
    glBegin(GL_POINTS);

    int r = 160;
    int x, y, d;
    x = 0;
    y = r;
    d = 1 - r;

    while (x <= y) {
        GLfloat X = x / 200.0;
        GLfloat Y = y / 200.0;

        glVertex2f(X, Y);
        glVertex2f(Y, X);
        glVertex2f(-X, Y);
        glVertex2f(-Y, X);
        glVertex2f(X, -Y);
        glVertex2f(Y, -X);
        glVertex2f(-X, -Y);
        glVertex2f(-Y, -X);

        if (d < 0)
            d += 2 * x + 3;
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    glEnd();
    glFlush();
    glutSwapBuffers();
}

void MidBresehamEllipse() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(1.0);
    glBegin(GL_POINTS);

    int a = 160;
    int b = 120;

    int x, y;
    float d1, d2;
    x = 0;
    y = b;
    d1 = b * b + a * a * (-b + 0.25);

    GLfloat X = x / 200.0;
    GLfloat Y = y / 200.0;
    glVertex2f(X, Y);
    glVertex2f(-X, Y);
    glVertex2f(X, -Y);
    glVertex2f(-X, -Y);

    while (b * b * (x + 1) < a * a * (y - 0.5)) {
        if (d1 <= 0) {
            d1 += b * b * (2 * x + 3);
            x++;
        } else {
            d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
            x++;
            y--;
        }
        GLfloat X = x / 200.0;
        GLfloat Y = y / 200.0;
        glVertex2f(X, Y);
        glVertex2f(-X, Y);
        glVertex2f(X, -Y);
        glVertex2f(-X, -Y);
    }
    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) -
         a * a * b * b;
    while (y > 0) {
        if (d2 <= 0) {
            d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
            x++;
            y--;
        } else {
            d2 += a * a * (-2 * y + 3);
            y--;
        }
        GLfloat X = x / 200.0;
        GLfloat Y = y / 200.0;
        glVertex2f(X, Y);
        glVertex2f(-X, Y);
        glVertex2f(X, -Y);
        glVertex2f(-X, -Y);
    }

    glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    // MidBresehamLine(0, 0, 8, 5);
    // MidBresehamLine(0, 0, 5, 8);
     MidBresehamLine(0, 0, -8, -5);
    // MidBresehamLine(0, 0, -5, -8);

    glutInit(&argc, argv);  //��ʼ��
    //������ʾ��ʽ��RGB��ɫ��������
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 200);     //�����ڴ��ڵ�����λ��
    glutInitWindowSize(400, 400);         //���ô��ڴ�С
    glutCreateWindow("Բ");               //��������
    glutDisplayFunc(MidBresehamCircle);   //����һ������
    glutCreateWindow("��Բ");             //��������
    glutDisplayFunc(MidBresehamEllipse);  //����һ������
    glutMainLoop();                       //������Ϣѭ��

    return 0;
}