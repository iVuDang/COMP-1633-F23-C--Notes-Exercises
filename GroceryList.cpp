/*
 *
 *     search     takes a name
 *                the grocery list is search for this name and if it is found,
 *                the boolean, found, parameter is set to true and the pointer,
 *                here, is set to point to the node containing the name;
 *                otherwise if the name is not found, the found parameter is
 *                set to false and here is set to point to the node with the
 *                name that would follow the name being searched for,
 *                i.e. the name’s alphabetic successor.
 *
 *                Details:
 *                Since the list can be traversed in either direction, this
 *                function will start searching from the head node for names
 *                that start with the letters 'a' through 'm'; the search will
 *                start from the tail node for names starting with the letters
 *                'n' through 'z'.
 *
 */
