GR='\033[1;34m'
NC='\033[0m' # No Color
echo "${GR}Building and running test suite..${NC}"
make tests
./gba_tests

