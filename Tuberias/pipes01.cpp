#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <cmath>

int main() {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Error al crear la tuberia");
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    pid = fork();
    if (pid == -1) {
        printf("Fallo en el fork \n");
        return -1;
    } else if (pid == 0) {
        close(pipe_fd[1]);

        // Proceso hijo
        int r;
        double area;

        ssize_t bites_leidos = read(pipe_fd[0], &r, sizeof(int));

        if (bites_leidos == -1) {
            perror("Error al leer desde la tuberia");
            exit(EXIT_FAILURE);
        } else if (bites_leidos == 0) {
            exit(EXIT_SUCCESS);
        }

        area = M_PI * r * r;
        printf("El área del círculo con radio %d es %.2lf\n", r, area);

        close(pipe_fd[0]);
    } else {
        close(pipe_fd[0]);

        int r;
        printf("Ingrese el radio del círculo: ");
        scanf("%d", &r);

        write(pipe_fd[1], &r, sizeof(int));
        close(pipe_fd[1]);
        wait(NULL);
    }

  return 0;
}
