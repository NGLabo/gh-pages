 
# Utility script for deployment process

# Reset folders
rm -rf dist

# Build files
yarn install
yarn re:build
yarn pa:build

# Prepare files
rm -rf docs
mv dist docs
cp CNAME docs
cp LICENSE docs
cp README.md docs
cp public/robots.txt docs
