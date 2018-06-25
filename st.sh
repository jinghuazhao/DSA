# 25-6-2018 JHZ

git add README.md
git commit -m "README"
for d in doc C C++ java python st.sh
do
   git add $d
   git commit -m "$d"
done
git push
