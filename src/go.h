#define MASTER 0
#define CMP_MAX 64
#define USAGE \
    "mpirun -np k ./build/go -P -M < data.txt\
        \n-P: [V|H] -> Vertical or Horizontal\
        \n-M: [V|S] -> Verbose or Silent"

enum LogLevel { SILENT, VERBOSE };

enum Partition { VERTICAL, HORIZONTAL };

struct RuntimeInfo {
    enum LogLevel log;
    enum Partition mode;
};

void parse_args(int argc, char *argv[], struct RuntimeInfo *info);
