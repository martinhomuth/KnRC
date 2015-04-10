/* qsort.h --- 
 * 
 * Filename: qsort.h
 * Description: Implementation of the quicksort algorithm. 
 * Author: Martin Homuth
 * Created: Thu Apr  9 12:15:36 2015 (+0200)
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

void q_sort(void *lineptr[], int left, int right,
	    int (*comp)(void*,void*),int order);

/* qsort.h ends here */
