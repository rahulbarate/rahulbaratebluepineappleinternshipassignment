#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
	char *word;
	struct node *left, *right;
};
bool wordFound = false;
void checkThisWord(int wordLength, char *characters, int *charPositions, char *word);
// Create a node
struct node *newNode(char *word)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->word = (char *)malloc(strlen(word) + 1 * sizeof(char));
	//   temp->key = item;
	strcpy(temp->word, word);
	temp->left = temp->right = NULL;
	return temp;
}

// Inorder Traversal
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%s -> ", root->word);
		inorder(root->right);
	}
}

struct node *preOrder(struct node *root, char *characters, char *rootICameWith)
{
	if (root != NULL)
	{
		if (root->word[0] == characters[0] && strcmp(root->word, rootICameWith) != 0)
		{
			return root;
		}
		preOrder(root->left, characters, rootICameWith);
		preOrder(root->right, characters, rootICameWith);
	}
	else
	{
		return NULL;
	}
}

// Insert a node
struct node *insert(struct node *node, char *word)
{
	// Return a new node if the tree is empty
	if (node == NULL)
		return newNode(word);

	// Traverse to the right place and insert the node
	if (strcmp(word, node->word) < 0)
		node->left = insert(node->left, word);
	else
		node->right = insert(node->right, word);

	return node;
}

struct node *getNewRoot(struct node *root, char *characters, char *word)
{
	struct node *newroot = preOrder(root, characters, root->word);
	if (newroot == NULL)
	return NULL;
	else
	return newroot;
}
void search(struct node *root, int wordLength, char *characters, int *charPositions)
{
onFirstIF:
	if (root == NULL)
	{
		if (wordFound == false)
		{
			printf("Data Not Found!");
		}
		return;
	}
	if (root->word[0] == characters[0])
	{
		if (strlen(root->word) != wordLength)
		{
			//first character is same but length is not that means it is there somewhere in that subtree
			//so getting next node to explore
			root = getNewRoot(root, characters, root->word);
			goto onFirstIF;
		}
		else
		{
			// printf("\ninside if1");
			checkThisWord(wordLength, characters, charPositions, root->word);

			//getting new node to check other remaining words
			root = getNewRoot(root, characters, root->word);
			goto onFirstIF;
		}
	}
outOfIF:
	if (characters[0] < root->word[0])
	{
		// printf("\ninside if2");
		search(root->left, wordLength, characters, charPositions);
	}
	if (characters[0] > root->word[0])
	{
		// printf("\ninside if3");
		search(root->right, wordLength, characters, charPositions);
	}
}

void preOrderSearch(struct node *root, int wordLength, char *characters, int *charPositions)
{
	if (root != NULL)
	{
		checkThisWord(wordLength, characters, charPositions, root->word);
		// printf("\n%s",root->word);
		preOrderSearch(root->left, wordLength, characters, charPositions);
		preOrderSearch(root->right, wordLength, characters, charPositions);
	}
}

void checkThisWord(int wordLength, char *characters, int *charPositions, char *word)
{
	if (strlen(word) == wordLength)
	{
		//as the word length is same,check for rest of the characters.
		// printf("\n inside checkThisWord if 1");
		int i;
		for (i = 0; i < strlen(characters); i++)
		{
			// printf("\nfinding...");
			// printf("%s",word);
			// printf("\n%c",word[charPositions[i]-1]);
			// printf("\n%c",characters[i]);
			if (word[charPositions[i] - 1] != characters[i])
			{
				// wordFound = false;
				// printf("\ni am out");
				return;
			}
		}
		wordFound = true;
		printf("\nis this the word you are looking for : %s", word);
	}
}

// Driver code
int main()
{

	struct node *root = NULL;
	int wordLength, i, totalchars;
	int *charPositions;
	char *characters;

	//adding data
	root = insert(root, "practice");
	root = insert(root, "main");
	root = insert(root, "dimension");
	root = insert(root, "snow");
	root = insert(root, "replacement");
	root = insert(root, "compound");
	root = insert(root, "stomach");
	root = insert(root, "literature");
	root = insert(root, "cool");
	root = insert(root, "fool");
	root = insert(root, "foot");
	root = insert(root, "application");

	// inorder(root);
	// printf("");

	//accepting all required inputs.
	printf("\nWhat is the word length? : ");
	scanf("%d", &wordLength);

	printf("\nHow many characters do you know? : ");
	scanf("%d", &totalchars);

	characters = (char *)malloc(totalchars * sizeof(char *));
	printf("\nEnter characters you know in order(do not use space separate) : ");
	scanf("%s", characters);
	if (strlen(characters) != totalchars)
	{
		printf("\nEnter all characters! ");
		exit(0);
	}

	charPositions = (int *)calloc(totalchars, sizeof(int));
	printf("\nEnter the positions of these characters in order(use spaces to separate) : ");
	for (i = 0; i < strlen(characters); i++)
	{
		int data;
		scanf("%d", &data);
		if (data > wordLength || data < 0)
		{
			printf("Entered Invalid position!");
			exit(0);
		}
		charPositions[i] = data;
		// printf("Added");
	}

	if (charPositions[0] == 1)
	{
		//if first word is known then binary search
		search(root, wordLength, characters, charPositions);
	}
	else
	{
		//if first word is not known then preorder traversal
		preOrderSearch(root, wordLength, characters, charPositions);
	}
}