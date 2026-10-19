#define MASK 0x00000001

typedef struct TrieNode {
    struct TrieNode* children[2];
} Trie;

void insert_node(Trie* trie, int num);
int search_node(Trie* trie, int num);
void free_trie(Trie* trie); 
Trie* create_node();

int findMaximumXOR(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    Trie* trie = create_node();
    if (trie == NULL) exit(1);

    int max_xor = 0;
    insert_node(trie, nums[0]);

    for (int i = 1; i < numsSize; i++) {
        int current_max = search_node(trie, nums[i]);
        if (current_max > max_xor) {
            max_xor = current_max;
        }
        insert_node(trie, nums[i]);
    }

    //free_trie(trie);
    return max_xor;
}

Trie* create_node() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    if (node != NULL) {
        node->children[0] = NULL;
        node->children[1] = NULL;
    } else {
        exit(1);
    }
    return node;
}

void insert_node(Trie* trie, int num) {
    Trie* current = trie;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & MASK;
        if (current->children[bit] == NULL) {
            current->children[bit] = create_node();
        }
        current = current->children[bit];
    }
}

int search_node(Trie* trie, int num) {
    Trie* current = trie;
    int xor_result = 0;

    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & MASK;
        int toggled_bit = bit ^ 1; 

        if (current->children[toggled_bit] != NULL) {
            xor_result |= (1 << i);
            current = current->children[toggled_bit];
        } else {
            current = current->children[bit];
        }
    }
    return xor_result;
}

/*
void free_trie(Trie* trie) {
    if (trie == NULL) return;
    free_trie(trie->children[0]);
    free_trie(trie->children[1]);
    free(trie);
}
*/