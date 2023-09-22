 /**
   * print_buffer - writes the content of buffer to stdout.
   * @buffer: the content of a buffer.
   * @buff_ind: an index.
   */
void print_buffer(char buffer[], int *buff_ind)
{
	if(*buff_ind > 0)
		write(1, &buffer[0]; *buff_ind);
	*buff_ind = 0;
}
