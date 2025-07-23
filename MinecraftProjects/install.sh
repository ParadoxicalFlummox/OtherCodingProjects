urls=(
    https://cdn.modrinth.com/data/P7dR8mSH/versions/UapVHwiP/fabric-api-0.92.6%2B1.20.1.jar
    https://cdn.modrinth.com/data/uXXizFIs/versions/unerR5MN/ferritecore-6.0.1-fabric.jar
    https://cdn.modrinth.com/data/gvQqBUqZ/versions/vuuAe7ZA/lithium-fabric-mc1.20.1-0.11.3.jar
    https://cdn.modrinth.com/data/EsAfCjCV/versions/xcauwnEB/appleskin-fabric-mc1.20.1-2.5.1.jar
    https://cdn.modrinth.com/data/nvQzSEkH/versions/drol2x1P/Jade-1.20-Fabric-11.13.1.jar
    https://cdn.modrinth.com/data/u6dRKJwZ/versions/MMnbcAih/jei-1.20.1-fabric-15.20.0.112.jar
    https://cdn.modrinth.com/data/Xbc0uyRg/versions/7Ub71nPb/create-fabric-0.5.1-j-build.1631%2Bmc1.20.1.jar
)

for url in "${urls[@]}"; do
    wget -P mods/ $url
done
