use strict;
use warnings;

my $target = "bibbidibobbidiboo";
my $pattern = "(b|a)ib*";

while ($target =~ m/$pattern/g) {
  print "pattern match succeeded\n";
  print "Match: " . substr($target, $-[0], $+[0]-$-[0]) . "\n";
}