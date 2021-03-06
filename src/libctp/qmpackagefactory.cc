/*
 *            Copyright 2009-2012 The VOTCA Development Team
 *                       (http://www.votca.org)
 *
 *      Licensed under the Apache License, Version 2.0 (the "License")
 *
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


#include <votca/ctp/qmpackagefactory.h>
#include "votca_config.h"
#include "qmpackages/gaussian.h"
#include "qmpackages/turbomole.h"
#include "qmpackages/nwchem.h"

namespace votca { namespace ctp {

void QMPackageFactory::RegisterAll(void)
{
        QMPackages().Register<Gaussian>         ("gaussian");
        QMPackages().Register<Turbomole>        ("turbomole");
        QMPackages().Register<NWChem>           ("nwchem");
}
}}
