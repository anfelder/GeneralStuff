#!/usr/bin/perl
use strict;
use warnings;

use Path::Class;
print "Hello World!\n";


my $dir = dir('..','Python'); # ../Python

# Iterate over the content of ../Python
while (my $file = $dir->next) {
    
    # See if it is a directory and skip
    next if $file->is_dir();
    
    # Print out the file name and path
    print $file->stringify . "\n";
}