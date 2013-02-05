#
# kill_long_subprocess.py
#
# This is a little program that demonstrates how to kill a
# long-running process. 
#
# It starts a subprocess that may or may not have an infinite loop. It
# is assumed that the subprocess should execute quickly (like within
# 10 seconds). If the subprocess is not done in time, it is killed.

# This was inspired by the Stack Overflow conversation at:
# http://stackoverflow.com/questions/1191374/subprocess-with-timeout

import signal
import subprocess
from sys import argv

class TakingTooLong(Exception):
    pass

def alarm_handler(signum, frame):
    raise TakingTooLong

def run_thing(cmd):
    print "About to run the process"
    proc = subprocess.Popen(
        cmd,
        stderr=subprocess.STDOUT,
        stdout=subprocess.PIPE,
        shell=True)
    print "Created proc object"
    try:
        signal.signal(signal.SIGALRM, alarm_handler)
        signal.alarm(5) # in seconds
        print "Set alarm."
        print "About to communicate()."
        stdoutdata, stderrdata = proc.communicate()
        print "About to reset the alarm."
        signal.alarm(0)
    except TakingTooLong:
        print "Took too long."
        pid = proc.pid
        proc.kill()
        print "Killed process " + str(pid)


if __name__ == "__main__":
    cmd = " ".join(argv[1:])
    print "cmd: "+ cmd
    run_thing(cmd)

