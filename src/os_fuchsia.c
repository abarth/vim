/* vi:set ts=8 sts=4 sw=4 noet:
 *
 * VIM - Vi IMproved  by Bram Moolenaar
 *
 * QNX port by Julian Kinraid
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 */

#include "vim.h"

#include <magenta/device/console.h>

/*
 * Get the current window size in Rows and Columns.
 */
    int
mch_get_shellsize(void)
{
    ioctl_console_dimensions_t dims;
    ssize_t r = ioctl_console_get_dimensions(0, &dims);
    if (r != sizeof(dims)) {
        return -1;
    }
    Columns = dims.width;
    Rows = dims.height;
    return OK;
}

    void
term_set_winsize(int width, int height)
{
    // TODO(abarth): Not sure if we have a way to set the terminal size.
}

    void
mch_settmode(int tmode)
{
}

    void
get_stty(void)
{
}
