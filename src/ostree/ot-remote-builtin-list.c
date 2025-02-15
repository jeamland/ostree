/*
 * Copyright (C) 2015 Red Hat, Inc.
 *
 * SPDX-License-Identifier: LGPL-2.0+
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <https://www.gnu.org/licenses/>.
 */

#include "config.h"

#include "ot-main.h"
#include "ot-remote-builtins.h"

static gboolean opt_show_urls;

/* ATTENTION:
 * Please remember to update the bash-completion script (bash/ostree) and
 * man page (man/ostree-remote.xml) when changing the option list.
 */

static GOptionEntry option_entries[] = {
  { "show-urls", 'u', 0, G_OPTION_ARG_NONE, &opt_show_urls, "Show remote URLs in list", NULL },
  { NULL }
};

gboolean
ot_remote_builtin_list (int argc, char **argv, OstreeCommandInvocation *invocation, GCancellable *cancellable, GError **error)
{
  g_autoptr(GOptionContext) context = g_option_context_new ("");

  g_autoptr(OstreeRepo) repo = NULL;
  if (!ostree_option_context_parse (context, option_entries, &argc, &argv,
                                    invocation, &repo, cancellable, error))
    return FALSE;

  guint n_remotes = 0;
  g_auto(GStrv) remotes = ostree_repo_remote_list (repo, &n_remotes);

  if (opt_show_urls)
    {
      int max_length = 0;

      for (guint ii = 0; ii < n_remotes; ii++)
        max_length = MAX (max_length, strlen (remotes[ii]));

      for (guint ii = 0; ii < n_remotes; ii++)
        {
          g_autofree char *remote_url = NULL;

          if (!ostree_repo_remote_get_url (repo, remotes[ii], &remote_url, error))
            return FALSE;

          g_print ("%-*s  %s\n", max_length, remotes[ii], remote_url);
        }
    }
  else
    {
      for (guint ii = 0; ii < n_remotes; ii++)
        g_print ("%s\n", remotes[ii]);
    }

  return TRUE;
}
