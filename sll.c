

#include<stdio.h>
#include<malloc.h>


struct node
{
    int data;
    struct node* next;
};


struct node* head = NULL;


struct node* create_node(int);
void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_at_beginning();
void delete_at_end();
void delete_at_position(int);
void print_from_beginning();
void print_from_end(struct node*);
void search_data(int);
void update_node_data(int, int);
void empty_message(void);
int size_of_list();
int getData();
int getPosition();


int main()
{

    char user_active = 'Y';
    int user_choice;
    int data, position;

    while(user_active == 'Y' || user_active == 'y')
    {

        printf("\n\n------ Singly Linked List -------\n");
        printf("\n1. Insert a node at beginning");
        printf("\n2. Insert a node at end");
        printf("\n3. Insert a node at given position");
        printf("\n\n4. Delete a node from beginning");
        printf("\n5. Delete a node from end");
        printf("\n6. Delete a node from given position");
        printf("\n\n7. Print list from beginning");
        printf("\n8. Print list from end");
        printf("\n9. Search a node data");
        printf("\n10. Update a node data");
        printf("\n11. Exit");
        printf("\n\n------------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);

        printf("\n------------------------------\n");
        switch(user_choice)
        {
            case 1:
                printf("\nInserting a node at beginning");
                data = getData();
                insert_at_beginning(data);
                break;

            case 2:
                printf("\nInserting a node at end");
                data = getData();
                insert_at_end(data);
                break;

            case 3:
                printf("\nInserting a node at the given position");
                data = getData();
                position = getPosition();
                insert_at_position(data, position);
                break;

            case 4:
                printf("\nDeleting a node from beginning\n");
                delete_at_beginning();
                break;

            case 5:
                printf("\nDeleting a node from end\n");
                delete_at_end();
                break;

            case 6:
                printf("\nDelete a node from given position\n");
                position = getPosition();
                delete_at_position(position);
                break;

            case 7:
                printf("\nPrinting the list from beginning\n\n");
                print_from_beginning();
                break;

            case 8:
                printf("\nPrinting the list from end\n\n");
                print_from_end(head);
                break;

            case 9:
                printf("\nSearching the node data");
                data = getData();
                search_data(data);
                break;

            case 10:
                printf("\nUpdating the node data");
                data = getData();
                position = getPosition();
                update_node_data(data, position);
                break;

            case 11:
                printf("\nProgram was terminated\n\n");
                return 0;

            default:
                printf("\n\tInvalid Choice\n");
        }

        printf("\n...............................\n");
        printf("\nDo you want to continue? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }

    return 0;
}



void empty_message()
{
    printf("\n\tList is Empty!\n");
}


void memory_message()
{
    printf("\nMemory can't be allocated\n");
}


struct node* create_node(int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        memory_message();
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


void insert_at_beginning(int data)
{
    struct node* new_node = NULL;
    new_node = create_node(data);

    if(new_node != NULL)
    {
        new_node->next = head;
        head = new_node;
        printf("\n* Node with data %d was Inserted\n", data);
    }
}


void insert_at_end(int data)
{
    struct node* new_node = NULL;
    new_node = create_node(data);

    if(new_node != NULL)
    {
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            struct node* last = head;

           
            while(last->next != NULL)
            {
                last = last->next;
            }

          
            last->next = new_node;
        }
        printf("\n* Node with data %d was Inserted\n", data);
    }
}



void insert_at_position(int data, int pos)
{
    
    int list_size = 0;
    list_size = size_of_list();

   
    if(head == NULL && (pos <= 0 || pos > 1))
    {
        printf("\nInvalid position to insert a node\n");
        return;
    }

    if(head != NULL && (pos <= 0 || pos > list_size))
    {
        printf("\nInvalid position to insert a node\n");
        return;
    }

    struct node* new_node = NULL;
    new_node = create_node(data);

    if(new_node != NULL)
    {
        struct node* temp = head;

       
        int count = 1;
        while(count < pos-1)
        {
            temp = temp -> next;
            count += 1;
        }

        if(pos == 1)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            new_node->next = temp->next;
            temp->next = new_node;
        }
        printf("\n* Node with data %d was Inserted\n", data);
    }
}



void delete_at_beginning()
{
    if(head == NULL)
    {
        empty_message();
        return;
    }

    struct node* temp = head;
    int data = head->data;

    head = head->next;
    free(temp);

    printf("\n* Node with data %d was Deleted\n", data);
}



void delete_at_end()
{
    if(head == NULL)
    {
        empty_message();
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    int data;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    data = temp->data;

   
    if(temp == head)
    {
        free(temp);
        head = NULL;
    }

    else
    {
        free(temp);
        prev->next = NULL;
    }
    printf("\n* Node with data %d was Deleted\n", data);
}



void delete_at_position(int pos)
{
  
    int list_size = 0;
    list_size = size_of_list();

   
    if(pos <= 0 || pos > list_size)
    {
        printf("\nInvalid position to delete a node\n");
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    int count = 1;

    while(count < pos)
    {
        prev = temp;
        temp = temp->next;
        count += 1;
    }

    int data = temp->data;

    if(temp == head)
    {
        head = head->next;
        free(temp);
    }

    else
    {
        prev->next = temp->next;
        free(temp);
    }
    printf("\n* Node with data %d was Deleted\n", data);

}


void search_data(int data)
{
    int position = 0;
    int flag = 0;

    struct node* temp = head;

    while(temp != NULL)
    {
        position += 1;
        if(temp->data == data)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 0)
    {
        printf("\nNode with data %d was not found!\n", data);
    }
    else
    {
        printf("\nFound data at %d position\n", position);
    }
}


void update_node_data(int new_data, int pos)
{
    
    int list_size = 0;
    list_size = size_of_list();

    
    if(pos <= 0 || pos > list_size)
    {
        printf("\nInvalid position to update a node\n");
        return;
    }

    struct node* temp = head;
    int count = 1;

    while(count < pos)
    {
        temp = temp->next;
        count += 1;
    }

    temp->data = new_data;
    printf("\nUpdated node data is %d\n", new_data);
}


void print_from_beginning()
{
    if(head == NULL)
    {
        empty_message();
        return;
    }

    struct node* temp = head;

    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}


void print_from_end(struct node* head)
{
    if(head == NULL)
    {
        return;
    }
    print_from_end( head->next );
    printf("%d  ", head->data);
}

int size_of_list()
{
    struct node* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}


int getData()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);

    return data;
}


int getPosition()
{
    int pos;

    printf("\nEnter Position: ");
    scanf("%d", &pos);

    return pos;
}
