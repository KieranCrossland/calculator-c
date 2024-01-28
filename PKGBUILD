# Maintainer: Kieran B Crossland <kierancrossland1st@gmail.com>
pkgname=calculator-c
pkgver=0.4
pkgrel=1
pkgdesc="A simple arithmetic calculator written in C."
arch=('i686' 'pentium4' 'x86_64' 'arm' 'armv7h' 'armv6h' 'aarch64')
url="https://github.com/KieranCrossland/calculator-c"
license=('AGPL-3.0')
makedepends=('make' 'git')
source=("git+https://github.com/KieranCrossland/calculator-c")
md5sums=('SKIP')
srcdir='calculator-c'
depends=()

build () {
  cd "$srcdir/$pkgname"
  make  
}

package() {
  cd "$srcdir/$pkgname"
  install -Dm0755 -t "$pkgdir/usr/bin/" "calculator"
}

