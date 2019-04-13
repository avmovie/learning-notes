## environments

 when i log into the system,the shell undergoes a phase called **initialization** to set up the environment. This is usually a two-step process that involve the shell reading the followinf files 
>* `/etc/profile `
> 
>* `~/.profile`

And the process is as follows:
> 1. the shell checks to see whether the file /etc/profile exists
> 2. If it is exists ,the shell reads it. Otherwise,this file is skipped,No error message is displayed.
> 3. The shell checks to see whether the file .profile exists in you home director .Your home directory is the directory that you start out after you log in.
> 4. If it exists,the shell reads it;Otherwise ,the shell skips it.No error message is displayed.

As soon as both of these files have been read,the shell displays a prompt:`$`

This is the prompt where you can enter commands in order to have them executed.

Note - the shell initialization process detailed here 


