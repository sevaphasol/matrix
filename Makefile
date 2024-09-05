CC = g++
CFLAGS = -I include -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
	-Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor \
	-Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
	-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -fexceptions -pipe

SRCS_DIR = src
O_DIR = bin

EXE = matrix

SRC_FILES = $(wildcard $(SRCS_DIR)/*.cpp)
O_FILES = $(subst $(SRCS_DIR), $(O_DIR), $(SRC_FILES:.cpp=.o))

all: $(EXE)

$(O_DIR):
	mkdir -p $(O_DIR)

$(EXE): $(O_FILES)
	$(CC) $^ -o $@

$(O_DIR)/%.o: $(SRCS_DIR)/%.cpp $(O_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -fr $(O_DIR) $(BUILD_DIR)
