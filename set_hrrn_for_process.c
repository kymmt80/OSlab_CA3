#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  set_hrrn_for_process(atoi(argv[1]), atoi(argv[2]));
  exit();
}