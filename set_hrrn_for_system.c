#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  set_hrrn_for_system(atoi(argv[1]));
  exit();
}