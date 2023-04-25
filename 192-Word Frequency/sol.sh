# Read from the file words.txt and output the word frequency list to stdout.
# #  cat words.txt reads the contents of the file
# tr -s ' ' '\n' replaces all spaces with newlines to separate each word into its own line
# sort sorts the words in alphabetical order
# uniq -c counts the frequency of each unique word
# sort -rn sorts the words in descending order of frequency
# awk '{print 2""2 " "2""1}' prints the output in the desired format of "word count"
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2" "$1}'
