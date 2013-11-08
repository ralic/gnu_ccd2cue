/*
 cdt.c -- CD-Text format structure;

 Copyright (C) 2013 Bruno Félix Rezende Ribeiro <oitofelix@gnu.org>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3, or (at your option)
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * \file       cdt.c
 * \brief      _CD-Text_ format structure
 * \author     Bruno Félix Rezende Ribeiro (_oitofelix_)
 *             <oitofelix@gnu.org>
 * \date       2013
 * \version    0.2
 *
 * \copyright [GNU General Public License (version 3 or later)]
 *            (http://www.gnu.org/licenses/gpl.html)
 *
 * ~~~
 * This file is part of GNU ccd2cue.
 *
 * GNU ccd2cue is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNU ccd2cue is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ~~~
 *
 */


#include <config.h>
#include <stdio.h>
#include <assert.h>

#include "io.h"
#include "cdt.h"


void
cdt2stream (const struct cdt *cdt, FILE *stream)
{
  /* Assert the CDT structure is valid. */
  assert (cdt != NULL);

  /* Assert the stream is valid. */
  assert (stream != NULL);

  /* Write the _CD-Text_ structure to the stream. */
  xfwrite (cdt->entry, sizeof (*cdt->entry), cdt->entries, stream);

  /* Put the terminating NULL character. */
  xputc (0, stream);
}
