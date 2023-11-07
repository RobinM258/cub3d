#include <stdio.h>
#include <stdlib.h>

int ft_exec(char *av[], char *env[], int i, int fd) {
    av[i] = NULL;
    execve(av[0], av, env);
    printf("error\n");
    return 0;
}

int main( int ac, char *av[], char *env[] ) {
    int i = 0;
    int tmp_fd;
    pid_t fd[2];

    while (av[i] && av[i + 1]) {
        av[i] = av[i + 1];
        i = 0;
        while (av[i] && ft_strcmp(av[i], "|") != 0 && ft_strcmp(av[i], ";") != 0)
            i++;
        if (av[i] && ft_strcmp(av[0], "cd"))
            if (i != 1 && !chdir(av[1]))
                printf("error: cd: arg number\n");
        else if (av[i] && i < 1 && ft_strcmp(av[0], "|")) {
            pipe(fd);
            if (fork() == 0) { //fils
                close(fd[1]);
                dup2(fd[0], tmp_fd);
                close(fd[0]);
                ft_exec(av, env, i, tmp_fd);
            }
            else {
                close (fd[1]);
                dup2(fd[0], tmp_fd);
            }
        }
        else if (av[i] && i < 1 && ft_strcmp(av[0], ";")) {
            if (ft_exec(av, env, i))
        }
    }
}
