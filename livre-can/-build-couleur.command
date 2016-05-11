#!/bin/sh
set -x
DIR=`dirname $0` &&
cd $DIR &&
rm -f livre-can-couleur.pdf &&
#--- First pass
PDF_LATEX=`which pdflatex` &&
MAKE_INDEX=`which makeindex` &&
$PDF_LATEX --file-line-error --shell-escape '\newcommand\afficherDetailSchema{false}\input{livre-can.tex}' &&
touch ref.idx &&
#touch ref.lof &&
#touch ref.lot &&
#touch ref.prgm-spice &&
touch ref.toc &&
iteration=0 &&
while [ `cmp -s ref.idx livre-can.idx ; echo $?` -ne 0 ] \
    || [ `cmp -s ref.toc livre-can.toc ; echo $?` -ne 0 ] \
#   || [ `cmp -s ref.lot livre-can.lot ; echo $?` -ne 0 ] \
#   || [ `cmp -s ref.prgm-spice livre-can.prgm-spice ; echo $?` -ne 0 ] \
#   || [ `cmp -s ref.lof livre-can.lof ; echo $?` -ne 0 ]
do
  cp livre-can.idx ref.idx &&
#  cp livre-can.lof ref.lof &&
#  cp livre-can.lot ref.lot &&
#  cp livre-can.prgm-spice ref.prgm-spice &&
  cp livre-can.toc ref.toc &&
  $MAKE_INDEX -s $DIR/fichiers-inclus/style-indexes.ist livre-can.idx &&
  $PDF_LATEX --file-line-error --shell-escape '\newcommand\afficherDetailSchema{false}\input{livre-can.tex}' &&
  iteration=$((iteration+=1))
done &&
cp livre-can.pdf livre-can-couleur.pdf &&
echo "---------------- SUCCES $iteration iterations"
