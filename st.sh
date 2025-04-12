# 12-4-2025 JHZ

function github_pages()
{
  module load python/3.8
  source ~/rds/public_databases/software/py38/bin/activate
# pip install mkdocs-mermaid2-plugin
}

if [ "$(uname -n | sed 's/-[0-9]*$//')" == "login-q" ]; then
   module load ceuadmin/libssh/0.10.6-icelake
   module load ceuadmin/openssh/9.7p1-icelake
   module load ceuadmin/krb5
fi

github_pages
mkdocs build
mkdocs gh-deploy

git add README.md
git commit -m "README"
for d in doc C C++ java python st.sh
do
   git add $d
   git commit -m "$d"
done
git push
