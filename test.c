/*dico a integrer a tree*/

void buildTree()
{
	stack_t * stack = createStack(50);
	
	char * treeString = "(a(b(a(T)i(m(E)))))";
	int index = 0;
	
	while (treeString[index] != '\0')
	{		
		
		if (isOpenedParanthese(treeString[index]))
		{
			index++; /* Car suivant */
			
			/* addChild */
			printf("empile %c \n", treeString[index]);
			
			/* empiler */
			pushStack(stack, treeString[index]);
		}
		else if (isClosedParanthese(treeString[index]))
		{
			
			/* depiler */
			printf("depile %c\n", popStack(stack));
			
			if (! isClosedParanthese(treeString[index]))
			{
				index++;
				
				/* addSibling */
			}
		}
		else if (isComma(treeString[index]))
		{
			index++;
	
			/* addSibling */
		}

		index++;
		
	}+
}

int isOpenedParanthese(char car)
{
	return car == '(';
}

int isClosedParanthese(char car)
{
	return car == ')';
}

int isComma(char car)
{
	return car == ',';
}

void insertWord(char * word)
{
	unsigned int index = 0;
	unsigned int wordSize = strlen(word);
	
	while (index < wordSize)
	{
		printf("%c\n", word[index]);
		index++;
	}
	
	
}
