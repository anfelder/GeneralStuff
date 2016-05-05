 #!/usr/bin/perl
  use strict;
  use warnings;
  use Email::Send;
  use Email::Send::Gmail;
  use Email::Simple::Creator;

  my $email = Email::Simple->create(
      header => [
          From    => 'andrewfelder95@gmail.com',
          To      => 'npdunawa@email.uark.edu',
          Subject => 'Testing Perl Script',
      ],
      body => 'Email sent using a perl script',
  );

  my $sender = Email::Send->new(
      {   mailer      => 'Gmail',
          mailer_args => [
              username => 'andrewfelder95@gmail.com',
              password => '',
          ]
      }
  );
  eval { $sender->send($email) };
  die "Error sending email: $@" if $@;