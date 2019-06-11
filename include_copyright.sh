for i in $(find . -name '*.h' -o -name '*.cpp')
do
  if ! grep -q Copyright $i
  then
    cat copyright.txt $i >$i.new && mv $i.new $i
  fi
done